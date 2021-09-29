public class Sedan extends Vehicle {

    @Override
    public boolean canTakeTrip(int numPass, int distance) {
        if (numPass <= 4 && distance <= 25 && !(numPass < 1)) {
            return true;
        }
        return false;
    }

    @Override
    public int perHeadFare(int numPass, int distance, int minutes) {
        int fare = (50 + distance * 30 + minutes * 2) / numPass;
        return fare - (fare % 5);
    }

    @Override
    public void Message() {
        System.out.println("== Comfortable Sedan Ride ==");
    }
}
