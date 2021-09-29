public class SevenSeater extends Vehicle {
    @Override
    public boolean canTakeTrip(int passNumb, int distance) {
        if (passNumb <= 7 && distance >= 10 && !(passNumb < 1)) {
            return true;
        }
        return false;
    }
    

    @Override
    public int perHeadFare(int passNumb, int distance, int minutes) {
        int fare;

        if (distance < 10)
            fare = 300 / passNumb;
        else
            fare = (distance * 30) / passNumb;

        return fare - (fare % 5);
    }

    @Override
    public void Message() {
        System.out.println("== Ride with Friends and Family in Seven-Seater ==");
    }
}
