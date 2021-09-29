import static org.junit.Assert.*;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;



public class Testing {

    @Test
    public void generateVersesOfSongTest() {

        NinetyNineBottlesSong testone = new NinetyNineBottlesSong();
        String outputone = testone.verse(99);
        assertEquals("99 bottles of milk on the wall ,99 bottles of milk.Take one down and pass it around, 98 bottles of milk on the wall.", output);
    }

    @Test
    public void generateVersesOfSongAfterTakingDownOneBottlTest() {

        NinetyNineBottlesSong testtwo = new NinetyNineBottlesSong();
        String outputtwo = testtwo.verse(98);
        assertEquals("98 bottles of milk on the wall ,98 bottles of milk.Take one down and pass it around, 97 bottles of milk on the wall.", output);
    }


}