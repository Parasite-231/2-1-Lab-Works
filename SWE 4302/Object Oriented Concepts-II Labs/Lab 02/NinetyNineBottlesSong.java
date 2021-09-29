class NinetyNineBottlesSong {

    public void generateVersesOfSong(int numberOfBottles) {

        String wordInVerse = "bottles";
        String replacingWordInVerse = "one";
        int numberOfBottlesAfterTakingDownOne;

        if (numberOfBottles == 1) {
            wordInVerse = "bottle";
            replacingWordInVerse = "it";
        }
        System.out.print(numberOfBottles + " " + wordInVerse + " of milk on the wall, " + numberOfBottles + " " + wordInVerse + " of milk.\nTake " + replacingWordInVerse + " down and pass it around,");
        numberOfBottlesAfterTakingDownOne = numberOfBottles - 1;
        generateVersesOfSongAfterTakingDownOneBottle(numberOfBottlesAfterTakingDownOne, wordInVerse);

    }

    private void generateVersesOfSongAfterTakingDownOneBottle(int numberOfBottlesAfterTakingDownOne, String wordInVerse) {

        if (numberOfBottlesAfterTakingDownOne > 0) {
            System.out.println(numberOfBottlesAfterTakingDownOne + " " + wordInVerse + " of milk on the wall.");

        } else {
            System.out.println("no more bottles of milk on the wall.\nNo more bottles of milk on the wall, no more bottles of milk.\nGo to the store and buy some more, 99 bottles of milk on the wall.");

        }

    }
}