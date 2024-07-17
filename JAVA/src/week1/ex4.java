package week1;

public class ex4 {
    public static void main(String[] args) {
        int line2 =20;
        for (int i =1;i<=10;i++){
            if (i ==1 ){
                System.out.print("Miles   Kilometers   |    Miles    Kilometers");
            }
            System.out.println();
            System.out.printf("%2d%13.2f      |",i,i*1.609);
            for (int z=line2;z<=65;){
                line2=z+5;
                System.out.printf("%7d%12.2f",z,z/1.609);
                break;

            }
        }

    }

}
