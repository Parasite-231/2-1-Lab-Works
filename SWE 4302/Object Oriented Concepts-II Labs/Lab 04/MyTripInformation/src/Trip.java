public class Trip {
    private String rideType;
    private int Distance;
    private int minutes;
    private int number_of_Passengers;

    public Trip(String rideType, int Distance, int minutes, int number_of_Passengers) {
        this.rideType = rideType;
        this.Distance = Distance;
        this.minutes = minutes;
        this.number_of_Passengers = number_of_Passengers;
    }
    public String getRideType(){
        return rideType;
    }

    public void setRideType(String ride){
        rideType = ride;
    }

    public int getDistance(){
        return Distance;
    }

    public void setDistance(int dist){
        Distance = dist;
    }
    public int getMinutes(){
        return minutes;
    }

    public void setMinutes(int mins){
        minutes = mins;
    }
    public int getNumber_of_Passengers(){
        return number_of_Passengers;
    }

    public void setNumber_of_Passengers(int num){
        number_of_Passengers = num;
    }

    public int perHeadFare() {
        switch (this.rideType) {
            case "MOTOR_BIKE":
                var bike = new MotorBike();
                return bike.perHeadFare(getNumber_of_Passengers(), getDistance(), getMinutes());
            case "SEDAN":
                var sedan = new Sedan();
                return sedan.perHeadFare(getNumber_of_Passengers(), getDistance(), getMinutes());
            case "SEVEN_SEATER":
                var mpv = new SevenSeater();
                return mpv.perHeadFare(getNumber_of_Passengers(), getDistance(), getMinutes());
            default:
                System.out.println("Wrong Information!!!");
        }
        return -1;
    }

    public void requestTrip() {

        switch (this.rideType) {
            case "MOTOR_BIKE":
                Vehicle motorbike = new MotorBike();
                motorbike.makeTrip(getNumber_of_Passengers(), getDistance(), getMinutes());
                break;
            case "SEDAN":
                Vehicle sedan = new Sedan();
                sedan.makeTrip(getNumber_of_Passengers(), getDistance(), getMinutes());
                break;
            case "SEVEN_SEATER":
                Vehicle sevenseater = new SevenSeater();
                sevenseater.makeTrip(getNumber_of_Passengers(), getDistance(), getMinutes());
                break;
        }
    }

}