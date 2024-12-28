import java.util.*;

// Default person ordering is increasing order wrt name
record Person(String name, int age) implements Comparable<Person>{
	@Override
	public int compareTo(Person person){
		return name.compareTo(person.name());
	}
};

class OrderedSetEx2 {
	static void print(Set<Person> set){
		System.out.println("Set elements: ");
		for (var person: set)
			System.out.println(person);
	} //end-print

	static public void main(String argv[]){
		// Sorting criteria: 
		// Decreasing order wrt age
		// If the ages are equal, decreasing order wrt. name
		Comparator<Person> comparator = new Comparator<>(){
			@Override
			public int compare(Person person1, Person person2){
				if (person1.age() == person2.age())
					return person1.name().compareTo(person2.name());
				return person2.age() - person1.age();
			}
		};

		TreeSet<Person> persons = new TreeSet<>();            // Default ordering
//		TreeSet<Person> persons = new TreeSet<>(comparator);  // Custom ordering

		Person john = new Person("John", 20);
		System.out.println("Adding: " + john);
		persons.add(john);
		print(persons);
		System.out.println("----------------------------------------");

		Person alice = new Person("Alice", 25);
		System.out.println("Adding: " + alice);
		persons.add(alice);
		print(persons);
		System.out.println("----------------------------------------");

		Person bob = new Person("Bob", 20);
		System.out.println("Adding: " + bob);
		persons.add(bob);
		print(persons);
		System.out.println("----------------------------------------");

		Person jenny = new Person("Jenny", 25);
		System.out.println("Adding: " + jenny);
		persons.add(jenny);
		print(persons);
		System.out.println("----------------------------------------");

		System.out.println("Number of elements in the set: " + persons.size());

		System.out.println("The min element: " + persons.first());
		System.out.println("The max element: " + persons.last());

		System.out.println("The person that comes before " + bob + " is: " + persons.lower(bob));
		System.out.println("The person that comes after " + bob + " is: " + persons.higher(bob));
		System.out.println("----------------------------------------");

		System.out.println("Erasing: " + bob);
		persons.remove(bob);
		print(persons);

		Person adam = new Person("Adam", 20);
		System.out.println("Adding: " + adam);
		persons.add(adam);
		print(persons);
		System.out.println("----------------------------------------");

		if (persons.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
		System.out.println("Erasing all elements");
		persons.clear();
		print(persons);
		if (persons.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
	} //end-main
};