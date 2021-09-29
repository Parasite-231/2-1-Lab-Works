public class Main {

    public static void main(String[] args) {
	
        Store MyStore = new Store();
        Manager MichaelScott = new Manager("Michael Scott", 42, 40000);
        SalesAssociate JimHalpert = new SalesAssociate("Jim Halpert", 28, 30000);
        SalesAssociate PamBeesly = new SalesAssociate("Pam Beesly", 25, 30000);

        System.out.println("----Store has been generated successfully!----") ;
        JimHalpert.displaySalesAssociate();
        //MichaelScott.display() ;
        //PamBeesly.displaySalesAssociate() ;

        
        System.out.println();
        System.out.println();

        //sending informations to constructors
        MichaelScott.addProduct(1, "Logitech G304", 3400, 10, 2, 5, MyStore);
        MichaelScott.addProduct(2, "AMD Ryzen 3600", 17000, 20, 5, 7, MyStore);
        MichaelScott.addProduct(3, "Nvidia Geforce RTX 3090", 151000, 10, 3, 4, MyStore);

        System.out.println();
        System.out.println();

        //sending informations to constructors
        JimHalpert.sellProduct(1, 4, MyStore);
        PamBeesly.sellProduct(2, 17, MyStore);
        JimHalpert.sellProduct(1, 10, MyStore);

        System.out.println();
        System.out.println();

        //sending informations to constructors
        MichaelScott.addExistingProduct(1, 10, MyStore);

        System.out.println();
        System.out.println();

        MyStore.showStoreDetails();

        System.out.println();
        System.out.println();

        //sending informations to constructors
        JimHalpert.sellProduct(1, 15, MyStore);
        JimHalpert.sellProduct(2, 2, MyStore);
        JimHalpert.sellProduct(3, 9, MyStore);

        System.out.println();
        System.out.println();

        //sending informations to constructors
        MichaelScott.sendRequisition(MyStore);
        System.out.println();
        System.out.println();
        //accessing functions
        MichaelScott.showEmployeeInfo();
        JimHalpert.showEmployeeInfo();
        PamBeesly.showEmployeeInfo();

        System.out.println();
        System.out.println();

        //accessing functions
        MyStore.showStoreDetails();
    }
}
