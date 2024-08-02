import java.util.ArrayList;
import java.util.List;

public class Customer {

    private List<Account> accounts = new ArrayList<>();

    public void addAccount(Account account){
        this.accounts.add(account);
    }

    public void removeAccount(Account account){
        this.accounts.remove(account);
    }
}
