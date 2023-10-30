package com.rest.kafka.controller;

import com.rest.kafka.models.Profile;
import com.rest.kafka.services.Producer;
import org.apache.coyote.Response;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1/kafka")
public class MessageController {
    private final Producer producer;

    public MessageController(Producer producer) {
        this.producer = producer;
    }

    @GetMapping("/publish")
    public ResponseEntity<String> publish(@RequestParam("message") String message) {
        producer.sendMessage(message);
        return ResponseEntity.ok("Message sent to the topic surya");
    }

    @PostMapping("/profile")
    public ResponseEntity<String> sendProfile(@RequestBody Profile profile) {
        producer.sendJSONMessage(profile);
        return ResponseEntity.ok("Profile had been sent to the consumer");
    }
}
