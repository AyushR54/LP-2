import random

# Define the rules and responses
responses = {
    "hi": ["Hello!", "Hi there!", "Hey!"],
    "hello": ["Hello!", "Hi there!", "Hey!"],
    "how are you?": ["I'm doing well, thank you!", "I'm fine, thanks for asking!", "All good, thanks!"],
    "what is the weather today?": ["It's sunny today.", "I think it's going to rain later.", "It's quite cold outside."],
    "bye": ["Goodbye!", "See you later!", "Bye!"],
    "exit": ["Goodbye!", "See you later!", "Bye!"]
}

# Function to generate bot responses
def get_response(user_input):
    user_input = user_input.lower()
    for key in responses:
        if key in user_input:
            return random.choice(responses[key])
    return "I'm sorry, I didn't understand that."

# Main function to run the chatbot
def main():
    print("Bot: Hi! How can I help you today?")
    while True:
        user_input = input("You: ")
        if user_input.lower() == 'exit':
            print("Bot: " + get_response(user_input))
            break
        response = get_response(user_input)
        print("Bot: " + response)

if __name__ == "__main__":
    main()
