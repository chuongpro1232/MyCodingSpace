module com.example.ex3 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.ex3 to javafx.fxml;
    exports com.example.ex3;
}