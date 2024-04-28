package com.example.demo.controllers;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import com.example.demo.models.Product;

@RestController
public class HomeController {
    @GetMapping("/")
    public Product hello() {
        return new Product(null, 0, null);
    }
}
