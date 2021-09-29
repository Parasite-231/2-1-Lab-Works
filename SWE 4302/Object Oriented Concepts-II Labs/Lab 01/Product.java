public class Product {
    int i_num;
    String p_name;
    int price;
    int qty;
    int Min_qty;
    int Req_amt;

Product(int i_num, String p_name, int price, int qty, int min_qty, int req_amt) {
    this.i_num = i_num;
    this.p_name = p_name;
    this.price = price;
    this.qty = qty;
    Min_qty = min_qty;
    Req_amt = req_amt;
}


public String toString() {
    return "Product{" +
            "i_num=" + i_num +
            ", p_name='" + p_name + '\'' +
            ", price=" + price +
            ", qty=" + qty +
            ", Min_qty=" + Min_qty +
            ", Req_amt=" + Req_amt +
            '}';
    }
}
