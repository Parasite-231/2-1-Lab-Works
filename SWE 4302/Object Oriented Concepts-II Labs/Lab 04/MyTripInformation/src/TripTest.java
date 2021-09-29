import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.DisplayName;

class TripTest {

    @BeforeAll
    public static void shouldRunBeforeExecutingAllTheTest() {
        System.out.println("<--Running before executing all the test-->");

    }

    @AfterAll
    public static void shouldRunAfterExecutingAllTheTest() {

        System.out.println("<--Running after executing all the test-->");

    }

    @Test
    public void Sedan() {
        System.out.println("Testing per head fare for vechile SEDAN ");
        double actual = new Trip("SEDAN", 10, 10, 3).perHeadFare();
        assertEquals(120, actual);
    }


    @Test
    public void MotorBike_LessThan25() {
        System.out.println("Testing per head fare for vechile Motor Bike when less than 25km");
        double actual = new Trip("MOTOR_BIKE", 1, 2, 1).perHeadFare();
        assertEquals(25, actual);
    }


    @Test
    public void MotorBike_MoreThan25() {
        System.out.println("Testing per head fare for vechile Motor Bike when more than 25km");
        double actual = new Trip("MOTOR_BIKE", 5, 15, 1).perHeadFare();
        assertEquals(100, actual);
    }


    @Test
    public void SevenSeater_LessThan10KM() {
        System.out.println("Testing per head fare for vechile Seven Seater when less than 10km");
        double actual = new Trip("SEVEN_SEATER", 1, 2, 7).perHeadFare();
        assertEquals(40, actual);
    }


    @Test
    public void SevenSeater_MoreThan2KM() {
        System.out.println("Testing per head fare seven Seater when more than 2km");
        double actual = new Trip("SEVEN_SEATER", 100, 200, 6).perHeadFare();
        assertEquals(500, actual);
    }

}