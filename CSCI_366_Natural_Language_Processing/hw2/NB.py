import os 
import time
import re 
import math
from preprocess import preprocess
from methods import compute_prior_probabilities, compute_conditional_probabilities_with_add1, validate_predictions, get_validation_labels

def nb(train_data_path, test_data_path):
    # Step 1: Log method call 
    print("Entering Naive Bayes ... ")

    # Step 2: Record execution Time
    start_time = time.time()  # record time

    # Step 3: Extract and Sort the subdirectories dynamically for consistent ordering
    subdirectories = sorted([d for d in os.listdir(train_data_path) if os.path.isdir(os.path.join(train_data_path, d))])
    
    if len(subdirectories) != 2:
        print("Expected exactly 2 subdirectories within the train_data_path.")
        return
    
    # Step 4: Compute Prior Probabilities
    class1_path = os.path.join(train_data_path, subdirectories[0])
    class2_path = os.path.join(train_data_path, subdirectories[1])

    print("\nComputing Prior Probabilities...")
    class1_name, class1_prior, class2_name, class2_prior = compute_prior_probabilities(train_data_path)
    print(f"Prior Probabilities: {class1_name} {class1_prior}, {class2_name} {class2_prior}")

    # Step 5: Generate BOW for each Feature
    print("\nGenerating Bag of Words for each class...")
    class1_bow = preprocess(class1_path)
    print(f"{class1_name.capitalize()} BOW: {class1_bow}")

    print()
    class2_bow = preprocess(class2_path)
    print(f"{class2_name.capitalize()} BOW: {class2_bow}")
    print()

    # Step 6: Generate mapping for test classes
    print(f"Class Mapping:\n1 -> {class1_name}\n0 -> {class2_name}")

    # Step 7: Compute conditional probabilities with add 1 smoothing and extract vocabulary size
    print("\nComputing Conditional Probabilities with Add-1 Smoothing...")
    class1_probs, class1_bowsize, class2_probs, class2_bowsize, vocabulary_size = compute_conditional_probabilities_with_add1(class1_bow, class2_bow)

    print()
    print(f"Size of Bag of Word Features for {class1_name.capitalize()}: {class1_bowsize}")
    print(f"Size of Bag of Word Features for {class2_name.capitalize()}: {class2_bowsize}")
    print(f"Vocabulary Size: {vocabulary_size}")

    # Step 8: Generate Predictions
    with open("predictions.txt", "w") as output_file:
        output_file.write("Making predictions on the files\n")

    # Predicting with sorted inputs
    for folder in sorted(os.listdir(test_data_path)):
        folder_path = os.path.join(test_data_path, folder)       # Store file path of class
        if os.path.isdir(folder_path):                           # Ensure it is a directory
            with open("predictions.txt", "a") as output_file:
                output_file.write(f"--{folder.capitalize()}\n")

            for file_name in sorted(os.listdir(folder_path)):   # Iterate over all files in a class folder
                file_path = os.path.join(folder_path, file_name)
                if os.path.isfile(file_path):   
                    tokens = []                             # Initialize an empty list to store tokens for this file
                    with open(file_path, 'r', encoding='utf-8') as file:
                        # Process the file line by line and accumulate tokens
                        for line in file:
                            tokens += re.findall(r'\b\w+\b', line.lower())  # Extract words, ignoring punctuation and converting to lowercase

                    # Initialize log probabilities with the logarithm of prior probabilities
                    log_class1_prob = class1_prior
                    log_class2_prob = class2_prior

                    # Calculate log probabilities for class 1 using Add-1 smoothing
                    for token in tokens:
                        token_count_class1 = class1_bow[token] if token in class1_bow else 0  # Regular dictionary access with check
                        log_class1_prob += (token_count_class1 + 1) / (class1_bowsize + vocabulary_size)

                    # Calculate log probabilities for class 2 using Add-1 smoothing
                    for token in tokens:
                        token_count_class2 = class2_bow[token] if token in class2_bow else 0  # Regular dictionary access with check
                        log_class2_prob += (token_count_class2 + 1) / (class2_bowsize + vocabulary_size)

                    # Make prediction (1 for class1, 0 for class2)
                    predicted_label = 0 if log_class1_prob > log_class2_prob else 1
                    feature_probs = max(log_class1_prob, log_class2_prob)  # Use the max log probability for display

                    # Write to predictions file with the filename as the third column
                    with open("predictions.txt", "a") as output_file:
                        output_file.write(f"{predicted_label}              {feature_probs:.8f}              {file_name}\n")

    # Step 9: Generate and store model parameters 
    with open("parameters.txt", "w", encoding='utf-8') as param_file:
        param_file.write(f"{class1_name.capitalize()}\n")
        for token, prob in class1_probs.items():
            param_file.write(f"{token}: {prob:.8f}\n")
        param_file.write("\n")

        param_file.write(f"{class2_name.capitalize()}\n")
        for token, prob in class2_probs.items():
            param_file.write(f"{token}: {prob:.8f}\n")
        param_file.write("\n")

    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"NB() executed in {elapsed_time:.4f} seconds")