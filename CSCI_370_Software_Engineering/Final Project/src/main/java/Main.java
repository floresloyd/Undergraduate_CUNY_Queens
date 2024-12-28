// Main.java
public class Main {
    public static void main(String[] args) {
        BurgerFactory factory = new BurgerFactory();

        // Create cheeseburger
        Burger cheeseBurger = factory.createBurger("cheese");
        cheeseBurger.assemble();

        // Create veggie burger
        Burger veggieBurger = factory.createBurger("veggie");
        veggieBurger.assemble();

        // Create chicken burger
        Burger chickenBurger = factory.createBurger("chicken");
        chickenBurger.assemble();
    }
}
