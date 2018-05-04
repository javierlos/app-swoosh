import UIKit



class Question {
    var type: QuestionType
    var query: String
    var answer: String
    
    init(type: QuestionType, query: String, answer: String) {
        self.type = type
        self.query = query
        self.answer = answer
    }
}

enum QuestionType: String {
    case trueFalse = "The sky is blue."
    case multipleChoice = "Who is the ugliest Beatle: John, Paul, George, or Ringo?"
    case shortAnswer = "What is the capital of Oregon?"
    case essay = "In 50 words, explain molceular fusion."
    
    static let types = [trueFalse, multipleChoice, shortAnswer, essay]
}

enum AnswerType: String {
    case trueFalse = "True."
    case multipleChoice = "Sgt. Pepper."
    case shortAnswer = "Salem"
    case essay = "When people do anal"
    
    static let types = [trueFalse, multipleChoice, shortAnswer, essay]
}

class Answer{}


protocol QuestionGenerator {
    func generateRandomQuestion() -> Question
}

protocol AnswerGenerator: QuestionGenerator {
    func generateRandomAnswer() -> Answer
}

class Jeapardy: AnswerGenerator{
    func
}


class Quiz: QuestionGenerator{
    func generateRandomQuestion() -> Question {
        let randomNumeral = Int(arc4random_uniform(4))
        let randomType = QuestionType.types[randomNumeral]
        let randomQuery = randomType.rawValue
        let randomAnswer = AnswerType.types[randomNumeral].rawValue
        let randomQuestion = Question(type: randomType, query: randomQuery, answer: randomAnswer)
        return randomQuestion
    }
}

let quiz = Quiz()

let question = quiz.generateRandomQuestion()

print("Question Type: \(question.type) \n Query: \(question.query) \n Answer \(question.answer)")


















