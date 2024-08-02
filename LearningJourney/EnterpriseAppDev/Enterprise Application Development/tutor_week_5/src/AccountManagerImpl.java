public class AccountManagerImpl implements AccountManager{
    @Override
    public void deposit(Account account, double amount) {
        account.setBalance(account.getBalance()+amount);
    }

    @Override
    public void withdraw(Account account, double amount) {
        account.setBalance(account.getBalance()-amount);
    }
}
