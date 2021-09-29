public class Manager extends Employee{

Manager(String name, int age, int salary) {
        super(name, age, salary);

        this.name  = name ;
        this.age = age ;
        this.salary = salary ;
}

/*public void dislplay(){

    System.out.println("----Manager has been added!----");
    System.out.println("Name:"+name+"-- Age : "+age+"--Base Salary"+salary) ;

}*/

public void addProduct(int i_num, String p_name, int price, int qty, int Min_qty, int Req_amt, Store myStore) {
        Product p = new Product( i_num,p_name,price,qty,Min_qty,Req_amt);
        myStore.products.add(p);
}

public void addExistingProduct(int i, int qty, Store myStore) {
        myStore.products.get(i).qty+=qty;
}

public void sendRequisition(Store myStore) {

}


}