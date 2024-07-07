import java.util.Random;

public class Job implements Comparable<Job> {
    protected int arrivalTime;
    protected int cpuBurst;
    protected int priority;
    protected int exitTime;
    protected int turnAroundTime;
    protected int remainingTime;

    private static final Random rand = new Random();

    public Job() {
        this.arrivalTime = rand.nextInt(250) + 1; // Random between 1-250
        this.cpuBurst = rand.nextInt(14) + 2; // Random between 2-15
        this.priority = rand.nextInt(5) + 1; // Random between 1 (lowest) - 5 (highest)
        this.remainingTime = this.cpuBurst; // Initially, remaining time is the CPU burst time
    }

    public String toString() {
        return String.format("Arrival Time: %d, CPU Burst: %d, Priority: %d, Exit Time: %d, Turnaround Time: %d, Remaining Time: %d",
                             arrivalTime, cpuBurst, priority, exitTime, turnAroundTime, remainingTime);
    }

    @Override
    public int compareTo(Job other) {
        return Integer.compare(this.arrivalTime, other.arrivalTime);
    }
}
