module com.example.ex2 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.ex2 to javafx.fxml;
    exports com.example.ex2;
}