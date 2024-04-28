package com.example3.demo3.controllers;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.example3.demo3.controllers.dtos.StudentDTO;

import jakarta.validation.Valid;

@RestController
public class StudentController {
    @PostMapping("/students")
    public String createStudent(@RequestBody @Valid StudentDTO student) {
        return "Hello Student";
    }
}
