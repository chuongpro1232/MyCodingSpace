module com.example.week6ex2 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.week6ex2 to javafx.fxml;
    exports com.example.week6ex2;
}