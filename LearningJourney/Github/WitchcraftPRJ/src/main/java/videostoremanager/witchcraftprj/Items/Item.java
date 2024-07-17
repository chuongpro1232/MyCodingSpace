package videostoremanager.witchcraftprj.Items;

public class Item {
    private String id;
    private String title;
    private RentalType rentalType;
    private LoanType loanType;
    private int stock;
    private double rentalFee;
    private RentalStatus rentalStatus;

    public Item(String id, String title, RentalType rentalType, LoanType loanType, int stock, double rentalFee, RentalStatus rentalStatus) {
        this.id = id;
        this.title = title;
        this.rentalType = rentalType;
        this.loanType = loanType;
        this.stock = stock;
        this.rentalFee = rentalFee;
        this.rentalStatus = rentalStatus;
    }

    // Getters and Setters
    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public RentalType getRentalType() {
        return rentalType;
    }

    public void setRentalType(RentalType rentalType) {
        this.rentalType = rentalType;
    }

    public LoanType getLoanType() {
        return loanType;
    }

    public void setLoanType(LoanType loanType) {
        this.loanType = loanType;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public double getRentalFee() {
        return rentalFee;
    }

    public void setRentalFee(double rentalFee) {
        this.rentalFee = rentalFee;
    }

    public RentalStatus getRentalStatus() {
        return rentalStatus;
    }

    public void setRentalStatus(RentalStatus rentalStatus) {
        this.rentalStatus = rentalStatus;
    }

    // Other methods if needed
}