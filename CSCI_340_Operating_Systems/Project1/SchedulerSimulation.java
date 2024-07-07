import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Comparator;

public class SchedulerSimulation {
    private List<Job> jobs = new ArrayList<>();
    private static final int QUANTUM = 1; // Quantum time for Round Robin

    public void generateJobs(int numJobs) {
        for (int i = 0; i < numJobs; i++) {
            jobs.add(new Job());
        }
    }

    public void runSchedulingAlgorithms() {
        System.out.println("Running FIFO...");
        runFIFO(new ArrayList<>(jobs));

        System.out.println("\nRunning SJF (Shortest Job First)...");
        runSJF(new ArrayList<>(jobs));


        System.out.println("\nRunning HPF (Highest Priority First)...");
        runHPF(new ArrayList<>(jobs));

        System.out.println("\nRunning Round Robin (with context switch)...");
        runRoundRobin(new ArrayList<>(jobs), true);

        System.out.println("\nRunning Round Robin (without context switch)...");
        runRoundRobin(new ArrayList<>(jobs), false);

        System.out.println("\nRunning SRTF (Shortest Remaining Time First)...");
        runSRTF(new ArrayList<>(jobs));
    }

    private void runFIFO(List<Job> jobList) {
        jobList.sort(Job::compareTo);
        int currentTime = 0;
        for (Job job : jobList) {
            if (currentTime < job.arrivalTime) {
                currentTime = job.arrivalTime;
            }
            job.exitTime = currentTime + job.cpuBurst;
            job.turnAroundTime = job.exitTime - job.arrivalTime;
            currentTime = job.exitTime;
        }
        displayResults(jobList, "FIFO");
    }

    private void runSJF(List<Job> jobList) {
        jobList.sort((j1, j2) -> {
            if (j1.arrivalTime == j2.arrivalTime) {
                return Integer.compare(j1.cpuBurst, j2.cpuBurst);
            }
            return Integer.compare(j1.arrivalTime, j2.arrivalTime);
        });
        int currentTime = 0;
        for (Job job : jobList) {
            if (currentTime < job.arrivalTime) {
                currentTime = job.arrivalTime;
            }
            job.exitTime = currentTime + job.cpuBurst;
            job.turnAroundTime = job.exitTime - job.arrivalTime;
            currentTime = job.exitTime;
        }
        displayResults(jobList, "SJF");
    }

    private void runSRTF(List<Job> jobList) {
        if (jobList.isEmpty()) {
            return; // No jobs to process.
        }
    
        PriorityQueue<Job> queue = new PriorityQueue<>(Comparator.comparingInt(j -> j.remainingTime));
        jobList.sort(Comparator.comparingInt(j -> j.arrivalTime));
        int currentTime = jobList.get(0).arrivalTime;
        int index = 0;
        Job currentJob = null;
    
        while (!queue.isEmpty() || index < jobList.size()) {
            // Ensure that all jobs that have arrived by currentTime are added to the queue.
            while (index < jobList.size() && jobList.get(index).arrivalTime <= currentTime) {
                Job job = jobList.get(index++);
                job.remainingTime = job.cpuBurst; // Ensure remaining time is initialized properly.
                queue.add(job);
            }
    
            if (currentJob != null && currentJob.remainingTime > 0) {
                queue.add(currentJob);  // Re-add current job if it's preempted by a shorter one
            }
    
            if (!queue.isEmpty()) {
                currentJob = queue.poll();
            }
    
            if (currentJob != null) {
                currentJob.remainingTime--;
                if (currentJob.remainingTime == 0) {
                    currentJob.exitTime = currentTime + 1;
                    currentJob.turnAroundTime = currentJob.exitTime - currentJob.arrivalTime;
                    currentJob = null;  // Current job finished, set to null to fetch next job
                }
            }
    
            // Increment time by 1 unless no jobs are available and no jobs can be run
            currentTime++;
        }
    
        displayResults(jobList, "SRTF");
    }
    

    private void runHPF(List<Job> jobList) {
        jobList.sort((j1, j2) -> {
            if (j1.arrivalTime == j2.arrivalTime) {
                return Integer.compare(j2.priority, j1.priority);
            }
            return Integer.compare(j1.arrivalTime, j2.arrivalTime);
        });
        int currentTime = 0;
        for (Job job : jobList) {
            if (currentTime < job.arrivalTime) {
                currentTime = job.arrivalTime;
            }
            job.exitTime = currentTime + job.cpuBurst;
            job.turnAroundTime = job.exitTime - job.arrivalTime;
            currentTime = job.exitTime;
        }
        displayResults(jobList, "HPF");
    }

    private void runRoundRobin(List<Job> jobList, boolean useContextSwitch) {
        jobList.sort(Job::compareTo);
        List<Job> queue = new ArrayList<>();
        int currentTime = jobList.get(0).arrivalTime;
        int index = 0;
        while (!queue.isEmpty() || index < jobList.size()) {
            while (index < jobList.size() && jobList.get(index).arrivalTime <= currentTime) {
                queue.add(jobList.get(index));
                index++;
            }
    
            if (!queue.isEmpty()) {
                Job job = queue.remove(0);
                int timeSlice = Math.min(job.remainingTime, QUANTUM);
                job.remainingTime -= timeSlice;
                currentTime += timeSlice;
    
                if (useContextSwitch && !queue.isEmpty()) {
                    currentTime += 2; // context switch time
                }
    
                if (job.remainingTime > 0) {
                    queue.add(job);
                } else {
                    job.exitTime = currentTime; // Set exit time upon completion
                    job.turnAroundTime = job.exitTime - job.arrivalTime;
                }
            } else {
                currentTime++; // Ensure time moves forward if no job is processed
            }
        }
    
        displayResults(jobList, useContextSwitch ? "Round Robin (with context switch)" : "Round Robin (without context switch)");
    }
    
    private void displayResults(List<Job> jobList, String algorithm) {
        double totalTurnAroundTime = 0;
        int finalTime = jobList.stream().mapToInt(j -> j.exitTime).max().orElse(0);
        System.out.println(algorithm + " Results:");
        for (Job job : jobList) {
            System.out.println(job);
            totalTurnAroundTime += job.turnAroundTime;
        }
        double avgTurnAroundTime = totalTurnAroundTime / jobList.size();
        double throughput = (double) jobList.size() / (finalTime - jobList.get(0).arrivalTime);
        System.out.printf("Average Turnaround Time: %.2f\n", avgTurnAroundTime);
        System.out.printf("Throughput: %.3f jobs per unit time\n", throughput);
    }

    public static void main(String[] args) {
        SchedulerSimulation sim = new SchedulerSimulation();
        sim.generateJobs(20); // Generate 20 random jobs
        sim.runSchedulingAlgorithms();
        System.out.println("Execution Completed ...");
    }
}