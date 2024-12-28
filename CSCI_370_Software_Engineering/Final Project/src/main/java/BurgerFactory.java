// BurgerFactory.java
public class BurgerFactory {
    public Burger createBurger(String type) {
        switch (type.toLowerCase()) {
            case "cheese":
                return new CheeseBurger();
            case "veggie":
                return new VeggieBurger();
            case "chicken":
                return new ChickenBurger();
            default:
                throw new IllegalArgumentException("Invalid burger type: " + type);
        }
    }
}
