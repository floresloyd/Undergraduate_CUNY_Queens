// VeggieBurger.java
public class VeggieBurger implements Burger {
    private String patty;
    private String cheese;

    public VeggieBurger() {
        this.patty = "veggie";
        this.cheese = "vegan cheese";
    }

    @Override
    public void assemble() {
        System.out.println("Adding patty: " + patty);
        System.out.println("Adding cheese: " + cheese);
        System.out.println("Assembling veggie burger...");
        // Add additional ingredients
    }
}