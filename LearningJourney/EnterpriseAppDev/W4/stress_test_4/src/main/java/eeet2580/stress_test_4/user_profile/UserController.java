package eeet2580.stress_test_4.user_profile;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class UserController {
    @Autowired
    public UserService userService;
    @GetMapping ("/profile/str/{id}")
    public String showUserAsString(@PathVariable int id){
        return userService.showProfileAsStr(id);
    }
    @GetMapping ("/profile/json/{id}")
    public UserProfile showUserAsJson (@PathVariable int id){
        return userService.showProfileAsObj(id);
    }
}
