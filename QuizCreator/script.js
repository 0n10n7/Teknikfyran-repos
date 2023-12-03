class Quiz {
    
    constructor(name) {
      this.name = name;
      this.questions = [];

    }

    AddQuestion(name,amountOfQueries,contentOfQueries,multipleAnswers) {
        let question = new Question(name,amountOfQueries,multipleAnswers);
        question.AddInformation(contentOfQueries);
        this.questions.push(question);
    }
}
class Question{
    constructor(name,amountOfQueries,multipleAnswers){
        this.name = name;
        this.amountOfQueries = amountOfQueries;
        this.multipleAnswers = multipleAnswers;
        this.queries = [];
    }
    
    AddInformation(contentOfQueries){
        for(let i = 0; i < this.amountOfQueries; i++){
            this.queries.push(contentOfQueries[i]);
        }
    }
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
        let questionTitle = document.createElement('p');
        questionTitle.innerHTML = question.name;
        questionBody.append(questionTitle);
        question.queries.forEach(query => {
            let queryButton = document.createElement('input');
            let queryButtonLabel = document.createElement('label');
            queryButton.setAttribute('Type','radio');
            queryButton.setAttribute('name',question.name);
            queryButton.setAttribute('id',query.name);

            queryButtonLabel.setAttribute('id',query.name);
            queryButtonLabel.innerHTML=`${query}`;
            
            queryButton.classList.add('query');
            questionBody.append(queryButton);
            questionBody.append(queryButtonLabel);
        });
        
        quizBody.append(questionBody)
    });
    document.querySelector(".quiz").append(quizBody);
}
let queryCount = 0;
function addQuery(){
    let newLegend = document.createElement('legend');
    newLegend.innerHTML = `option ${++queryCount}`;
    let newInputQuery = document.createElement('input');
    document.querySelector(".creator").append(newLegend);
    document.querySelector(".creator").append(newInputQuery);
}

try {
    document.querySelector(".creator").addEventListener("submit", (event) => {
        event.preventDefault();
        //id or select all
        console.log(event.target.querySelector("input").value);
        
    });
    
    let submitButton = document.createElement('button');
    submitButton.setAttribute("type", "submit");
    submitButton.innerHTML = "Submit";
    document.querySelector(".creator").prepend(submitButton);
    
    let buttonAddQuery = document.createElement('button');
    buttonAddQuery.addEventListener("click",addQuery);
    buttonAddQuery.innerHTML = "add option";
    document.querySelector(".creator").prepend(buttonAddQuery);
  }
catch (error) {
    console.log(error);
    console.log("You are not in the quiz creator");
  }
  
// Only for testing purpouses
let queries = [
    "1",
    "2",
    "3"
];
let quiz = new Quiz("namn");
quiz.AddQuestion("hur många svars alternativ finns det", 3,queries, false);
queries[0]="1919 in the treaty of versaille";
queries[1]="1883 due to increased public preassure to make the drug generic";
queries[2]="never, they still have the trade mark";
queries.push("1967 due to public health concerns");
quiz.AddQuestion("When and how did Bayer lose the trademark to heroin?",queries.length,queries,false);
console.log(quiz);

