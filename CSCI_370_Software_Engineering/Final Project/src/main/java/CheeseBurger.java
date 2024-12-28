// CheeseBurger.java
public class CheeseBurger implements Burger {
    private String patty;
    private String cheese;

    public CheeseBurger() {
        this.patty = "beef";
        this.cheese = "american";
    }

    @Override
    public void assemble() {
        System.out.println("Adding patty: " + patty);
        System.out.println("Adding cheese: " + cheese);
        System.out.println("Assembling cheeseburger...");
        // Add additional ingredients
    }
}