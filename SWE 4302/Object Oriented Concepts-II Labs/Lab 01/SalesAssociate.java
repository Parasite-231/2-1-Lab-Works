//This class inherited Employee class
public class SalesAssociate extends Employee{

    SalesAssociate(String name, int age, int salary) {
        super(name, age, salary);//inheritance

        this.name = name ;
        this.age = age ;
        this.salary = salary ;
        

    }

public void displaySalesAssociate(){

    System.out.println("----Sales Associate has been added!----") ;
	System.out.println("Name:"+name+"-- Age : "+age+"--Base Salary"+salary) ;
}

public void sellProduct(int i, int qty, Store myStore) {
    myStore.products.get(i).qty-=qty;
    this.Bonus+=myStore.products.get(i).price*qty*0.01;
    System.out.println(myStore +" has been sold and " +name+ " has received a bonus of BDT "+Bonus) ;
    //System.out.println(" "+myStore+" has been sold and Pam Beesly has received a bonus of BDT "+Bonus) ;

    }
}
