public class MotorBike extends Vehicle {

    @Override
    public boolean canTakeTrip(int passNo, int dist) {
        if (passNo <= 1 && dist <= 10 && !(passNo < 1)) {
            return true;
        }
        return false;
    }

    @Override
    public int perHeadFare(int passNo, int dist, int minutes) {
        int fare = Math.max(25, dist * 20) / passNo;
        return fare - (fare % 5);
    }

    @Override
    public void Message() {
        System.out.println("== Ride Swift in Bike ==");
    }
}
