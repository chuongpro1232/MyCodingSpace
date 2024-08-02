package rmitfreelancerweb.postgresql.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import rmitfreelancerweb.postgresql.repository.UserRepo;

@RestController
@RequestMapping("/user")
public class UserController {
    private final UserRepo userRepo;

    public UserController(UserRepo userRepo) {
        this.userRepo = userRepo;
    }

    @GetMapping
    public ResponseEntity getAllUsers() {
        return ResponseEntity.ok(this.userRepo.findAll());
    }

}
