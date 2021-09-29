import java.util.ArrayList;

public class Store {
    ArrayList<Product> products; //storing products
    Store() {
        products = new ArrayList<>(); //dynamically allocated data
    }

public void showStoreDetails() {
   for (Product p:products){ 
        System.out.println(p.toString());
    }
   }
}
