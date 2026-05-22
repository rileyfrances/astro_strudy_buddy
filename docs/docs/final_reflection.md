# Final Reflection

## Prompt 1: Plan vs Reality
My original plan was to make a study game with questions, hints, retries, and score tracking. Most of those systems were completed successfully, including the Question, Player, Level, and Game classes. As I worked on the project, the retry and hint systems became more important than I originally expected because they made the game feel more interactive and educational.The biggest change from my original plan was adding multiple-choice rounds before typed-answer mastery rounds. At first, questions only used typed answers, but I realized that adding a recognition-learning phase first made the game feel smoother and more realistic for studying.Some planned features like save/load functionality and advanced progression systems were not completed because I focused more on finishing the gameplay loop, testing, and documentation.


## Prompt 2: Design Decisions You Would Change
If I restarted this project, I would separate the gameplay logic from the user interface and input handling. Right now, Game.cpp handles too many responsibilities at once, including question display, user input, progression, retry logic, and rewards.I would also redesign how multiple choice data is stored. Currently, Question objects store both question data and gameplay mode information. A cleaner design would separate question content from gameplay behavior.

## Prompt 3: What You Learned

### Technical
I became much more comfortable working with larger C++ projects using multiple files, CMake, and CTest. I also improved my understanding of vectors and object interaction while implementing the multiple-choice system.

### Design
The biggest design lesson I learned was the importance of separation of concerns. As Game.cpp grew larger, it became harder to manage because too many systems depended on it.

### Process
I learned how useful feature branches and pull requests are for organizing work. Earlier in the semester GitHub workflows felt confusing, but after repeating the process several times it became much more natural.


## Prompt 4: What's Left to Finish
1. Save/load functionality so progress can persist between runs.
2. More question content and categories to make the game feel larger.
3. Statistics and mastery tracking for long-term progress.
4. Better balancing for score and health rewards.
5. Refactoring Game.cpp into smaller systems.

## Prompt 5: Workflow Reflection
The branch and pull request workflow became much easier over time. Creating branches, committing changes, pushing code, and merging PRs now feels much more natural than it did earlier in the semester.The part that still feels awkward is GitHub specific review behavior and branch synchronization. I also ran into repository settings that prevented self approval reviews, which made the workflow slightly confusing.If I worked with another developer, pull requests and reviews would matter much more because they would help prevent merge conflicts and make code changes easier to understand.


## Prompt 6: AI Use
AI tools were used mainly for workflow guidance, planning, and implenentation when allowed. AI was especially useful for breaking larger tasks into smaller implementation steps and helping troubleshoot GitHub workflow issues. I still made the major design decisions myself, including the retry system and the decision to add multiple choice learning rounds before mastery typing rounds, and the bulk of the project was made without help from AI.
