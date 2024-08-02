public class DbConnection {
    private static DbConnection instance = new DbConnection();

    private DbConnection() {
    }

    public static DbConnection getInstance(){
        return instance;
    }

}
