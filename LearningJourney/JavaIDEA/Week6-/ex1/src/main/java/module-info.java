module meow.week6 {
    requires javafx.controls;
    requires javafx.fxml;


    opens meow.week6 to javafx.fxml;
    exports meow.week6;
}