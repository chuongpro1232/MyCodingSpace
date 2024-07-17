module com.example.testingfxml {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.testingfxml to javafx.fxml;
    exports com.example.testingfxml;
}