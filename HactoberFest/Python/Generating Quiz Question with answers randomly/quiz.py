import random

capitals = {
    'Alabama': 'Montgomery',
    'Alaska': 'Juneau',
    'Arizona': 'Phoenix',
    'Arkansas': 'Little Rock',
    'California': 'Sacramento',
    'Colorado': 'Denver',
    'Connecticut': 'Hartford',
    'Delaware': 'Dover',
    'Florida': 'Tallahassee',
    'Georgia': 'Atlanta',
    'Hawaii': 'Honolulu',
    'Idaho': 'Boise',
    'Illinois': 'Springfield',
    'Indiana': 'Indianapolis',
    'Iowa': 'Des Moines',
    'Kansas': 'Topeka',
    'Kentucky': 'Frankfort',
    'Louisiana': 'Baton Rouge',
    'Maine': 'Augusta',
    'Maryland': 'Annapolis',
    'Massachusetts': 'Boston',
    'Michigan': 'Lansing',
    'Minnesota': 'St. Paul',
    'Mississippi': 'Jackson',
    'Missouri': 'Jefferson City',
    'Montana': 'Helena',
    'Nebraska': 'Lincoln',
    'Nevada': 'Carson City',
    'New Hampshire': 'Concord',
    'New Jersey': 'Trenton',
    'New Mexico': 'Santa Fe',
    'New York': 'Albany',
    'North Carolina': 'Raleigh',
    'North Dakota': 'Bismarck',
    'Ohio': 'Columbus',
    'Oklahoma': 'Oklahoma City',
    'Oregon': 'Salem',
    'Pennsylvania': 'Harrisburg',
    'Rhode Island': 'Providence',
    'South Carolina': 'Columbia',
    'South Dakota': 'Pierre',
    'Tennessee': 'Nashville',
    'Texas': 'Austin',
    'Utah': 'Salt Lake City',
    'Vermont': 'Montpelier',
    'Virginia': 'Richmond',
    'Washington': 'Olympia',
    'West Virginia': 'Charleston',
    'Wisconsin': 'Madison',
    'Wyoming': 'Cheyenne',
}

num_quizzes = 35

for quiz_num in range(1, num_quizzes + 1):
    states = list(capitals.keys())
    random.shuffle(states)

    quiz_filename = f'capitalsquiz{quiz_num}.txt'
    answer_key_filename = f'capitalsquiz_answers{quiz_num}.txt'

    with open(quiz_filename, 'w') as quiz_file, open(answer_key_filename, 'w') as answer_key_file:
        # Write the header for the quiz.
        quiz_file.write('Name:\n\nDate:\n\n')
        quiz_file.write(f'State Capitals Quiz (Form {quiz_num})\n\n')

        # Shuffle the order of the capitals.
        shuffled_capitals = list(capitals.values())
        random.shuffle(shuffled_capitals)

        # Loop through the states, create questions, and write to the quiz and answer key files.
        for question_num in range(len(states)):
            # Get the correct answer.
            correct_answer = capitals[states[question_num]]

            # Create a list of wrong answers, excluding the correct one.
            wrong_answers = list(capitals.values())
            wrong_answers.remove(correct_answer)

            # Sample three wrong answers (or fewer if there are fewer available).
            num_wrong_answers = min(3, len(wrong_answers))
            selected_wrong_answers = random.sample(wrong_answers, num_wrong_answers)

            # Combine the correct answer and the sampled wrong answers.
            answer_options = [correct_answer] + selected_wrong_answers
            random.shuffle(answer_options)

            # Write the question to the quiz file.
            quiz_file.write(f'{question_num + 1}. What is the capital of {states[question_num]}?\n')
            for i in range(4):
                quiz_file.write(f"{'ABCD'[i]}. {answer_options[i]}\n")
            quiz_file.write('\n')

            # Write the answer key to the answer key file.
            answer_key_file.write(f"{question_num + 1}. {'ABCD'[answer_options.index(correct_answer)]}\n")

print("Quizzes and answer keys generated successfully.")
