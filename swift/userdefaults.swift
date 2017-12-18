//: Playground - noun: a place where people can play

import Foundation

let username = "hitweb"

UserDefaults.standard.set(username, forKey: "nickname")
UserDefaults.standard.set(129, forKey: "score");
UserDefaults.standard.set(["Riri", "Fifi", "Loulou"], forKey: "castors_juniors")

// quitter app
// relance app

let loadedName = UserDefaults.standard.string(forKey: "nickname")
let score = UserDefaults.standard.integer(forKey: "score")
let cousins = UserDefaults.standard.array(forKey: "castors_juniors")
