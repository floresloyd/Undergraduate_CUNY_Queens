// ChickenBurger.java
public class ChickenBurger implements Burger {
    private String patty;
    private String cheese;
    

    public ChickenBurger() {
        this.patty = "chicken";
        this.cheese = "cheddar";
    }

    @Override
    public void assemble() {
        System.out.println("Adding patty: " + patty);
        System.out.println("Adding cheese: " + cheese);
        System.out.println("Assembling chicken burger...");
        // Add additional ingredients
    }
}