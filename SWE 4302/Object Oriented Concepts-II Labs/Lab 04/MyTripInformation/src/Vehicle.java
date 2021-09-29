public class Vehicle {
    public boolean canTakeTrip(int PassNo, int Distance){
        return false;
    }

    public int perHeadFare(int PassNo, int Distance, int minutes){
        return -1;
    }

    public void Message(){
        System.out.println("This function will be overriden.");
    }

    void makeTrip(int PassNo, int Distance, int minutes) {
        Message();
        if (canTakeTrip(PassNo, Distance)) {
            System.out.println(Distance + " KM");
            System.out.println(minutes + " Minutes");
            System.out.println(perHeadFare(PassNo, Distance, minutes) + " Taka Per Person");
        } else {
            System.out.println("Invalid Trip Request");
        }
    }


}
