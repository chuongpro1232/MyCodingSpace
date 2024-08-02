public class main {
    public static void main(String[] args) {
//        DbConnection con1 = DbConnection.getInstance();
//        DbConnection con2 = DbConnection.getInstance();
//        System.out.println(con1);
//        System.out.println(con2);

        Product product = new FbProduct();

        product.setId(1);
        product.setName("Dr Thanh tea");

        product.productInfo();


    }
}
