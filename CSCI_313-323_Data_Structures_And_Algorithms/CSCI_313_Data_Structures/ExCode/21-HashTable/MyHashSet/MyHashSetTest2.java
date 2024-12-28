record Person(String name, int age){}

class MyArraySetTest2 {
	static void print(MySet<Person> set){
		System.out.println("Set elements: ");
		for (var person: set)
			System.out.println(person);
	} //end-print

	static public void main(String argv[]){
		MySet<Person> persons = new MyHashSet<>(); 

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
		
		System.out.println("Erasing: " + bob);
		persons.remove(bob);
		print(persons);
		System.out.println("----------------------------------------");

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