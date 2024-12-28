import java.util.Objects;

class Person2 {
    private String name;
    private int dept;
    private double gpa;

    public Person2(String name, int dept, double gpa){
        this.name = name;
        this.dept = dept;
        this.gpa = gpa;
    }

    /// Simply call Objects.hash
    @Override
    public int hashCode() {
        return Objects.hash(name, dept, gpa);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;

        Person2 other = (Person2) obj;
        return dept == other.dept &&
               Double.compare(other.gpa, gpa) == 0 &&
               Objects.equals(name, other.name);
    }    

    @Override
    public String toString(){
        return String.format("Person {name: %s, dept: %d, gpa: %.2f}", name, dept, gpa);
    }
}

class JavaHashCodeEx2 {
    public static void main(String[] args){
        Person2 p1 = new Person2("John", 1, 3.20);

        System.out.println("Person2: " + p1);
        System.out.println("p1.hashCode(): " + p1.hashCode());
        System.out.println("------------------------------------------------");

        Person2 p2 = new Person2("John", 1, 3.45);
        System.out.println("Person2: " + p2);
        System.out.println("p1.hashCode(): " + p2.hashCode());
        System.out.println("------------------------------------------------");

        Person2 p3 = new Person2("Alice", 5, 3.55);
        System.out.println("Person3: " + p3);
        System.out.println("p3.hashCode(): " + p3.hashCode());
        System.out.println("------------------------------------------------");
    }
}
