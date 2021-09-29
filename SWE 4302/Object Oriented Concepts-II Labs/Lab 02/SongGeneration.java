public class SongGeneration {

    public static void main(String[] args) {

        NinetyNineBottlesSong verses = new NinetyNineBottlesSong();
        int countOfBottles;

        for (countOfBottles = 99; countOfBottles > 0; countOfBottles--) {
            verses.generateVersesOfSong(countOfBottles);

        }
    }
}