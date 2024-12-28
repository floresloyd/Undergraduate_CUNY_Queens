import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

class Person1 {
    private String name;
    private int dept;
    private double gpa;

    public Person1(String name, int dept, double gpa){
        this.name = name;
        this.dept = dept;
        this.gpa = gpa;
    }

    /// Implement a custom hashCode function
    @Override
    public int hashCode() {
        // Choose prime numbers for better distribution
        final int prime = 31;
        
        int result = 1;
        result = prime * result + Objects.hashCode(name);
        result = prime * result + dept;
        long gpaBits = Double.doubleToLongBits(gpa);
        result = prime * result + (int) (gpaBits ^ (gpaBits >>> 32));
        
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;

        Person1 other = (Person1) obj;
        return dept == other.dept &&
               Double.compare(other.gpa, gpa) == 0 &&
               Objects.equals(name, other.name);
    }

    @Override
    public String toString(){
        return String.format("Person {name: %s, dept: %d, gpa: %.2f}", name, dept, gpa);
    }
}

class JavaHashCodeEx1 {
    public static void main(String[] args){
        Person1 p1 = new Person1("John", 1, 3.20);

        System.out.println("Person1: " + p1);
        System.out.println("p1.hashCode(): " + p1.hashCode());
        System.out.println("------------------------------------------------");

        Person1 p2 = new Person1("John", 1, 3.45);
        System.out.println("Person1: " + p2);
        System.out.println("p1.hashCode(): " + p2.hashCode());
        System.out.println("------------------------------------------------");

        Person1 p3 = new Person1("Alice", 5, 3.55);
        System.out.println("Person3: " + p3);
        System.out.println("p3.hashCode(): " + p3.hashCode());
        System.out.println("------------------------------------------------");
    }
}
