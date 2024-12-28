class Parent {
    public void myMethod() {
        System.out.println("In Parent");
    }
}

class Child extends Parent {
    public void myMethod1() {
        System.out.println("In Child");
    }
}

public class App {
	public static void main(String[] args) {
		Parent o = new Child();
		o.myMethod();
	} //end-main
} //end-App
