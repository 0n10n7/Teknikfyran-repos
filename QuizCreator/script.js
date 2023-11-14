class Quiz {
    
    constructor(name) {
      this.name = name;
    }
    questions = [];

    AddQuestion(name,amountOfQueries,contentOfQueries,multipleAnswers) {
        let question = new Question(name,amountOfQueries,multipleAnswers);
        AddInformation(contentOfQueries);
        questions.push(question);
    }
}
class Question{
    constructor(name){
        this.name = name;
        this.amountOfQueries;
        this.multipleAnswers
    }
    AddInformation(contentOfQueries){

    }
    queries = [];
}
class Query{
    constructor(name, correct){
        this.name = name;
        this.correct = correct;
    }
}

function RenderQuestionaire(quiz) {
    let quizBody = document.createElement('div');
    quizBody.classList.add("quizDiv");
    quiz.questions.forEach(question => {
        let questionBody = document.createElement('div');
        question.queries.forEach(element => {
            let query = document.createElement('button');
            query.classList.add('query');
            questionBody.append(query);
        });
        quizBody.append(questionBody)
    });
    document.body.append(quizBody);
}
let quiz = new Quiz("namn");
quiz.AddQuestion("hur många svars alternativ finns det", 3, false);
