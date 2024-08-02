package rmitfreelancerweb.postgresql.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import rmitfreelancerweb.postgresql.repository.ServiceRepo;
import rmitfreelancerweb.postgresql.repository.UserRepo;

@RestController
@RequestMapping("/service")
public class ServiceController {
    private final ServiceRepo serviceRepo;

    public ServiceController(ServiceRepo serviceRepo) {
        this.serviceRepo = serviceRepo;
    }

    @GetMapping
    public ResponseEntity getAllUsers() {
        return ResponseEntity.ok(this.serviceRepo.findAll());
    }

}
