import org.junit.Test;
import static org.junit.Assert.*;

public class BurgerFactoryTest {

    @Test
    public void testCreateBurger() {
        BurgerFactory factory = new BurgerFactory();

        Burger burger = factory.createBurger("cheese");
        assertNotNull(burger);

        assertTrue(burger instanceof CheeseBurger);
    }

    @Test
    public void testInvalidBurgerType() {
        BurgerFactory factory = new BurgerFactory();

        try {
            Burger burger = factory.createBurger("invalid");
            fail("Expected IllegalArgumentException");
        } catch (IllegalArgumentException e) {
            assertEquals("Invalid burger type: invalid", e.getMessage());
        }
    }
}
