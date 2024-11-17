import pyfpgrowth

def read_transactions(file_path):

    transactions = []
    with open(file_path, 'r') as file:
        for line in file:
            transaction = line.strip().split()
            transactions.append(transaction)
    return transactions

def generate_association_rules(transactions, min_support, min_confidence):
    patterns = pyfpgrowth.find_frequent_patterns(transactions, min_support)
    rules = pyfpgrowth.generate_association_rules(patterns, min_confidence)
    return rules

if _name_ == "_main_":
    input_file = "transactions3.txt"
    min_support = 0.1
    min_confidence = 0.5
    transactions = read_transactions(input_file)
    rules = generate_association_rules(transactions, min_support, min_confidence)
for rule, confidence in rules.items():
        antecedent, consequent = rule
        print(f"{antecedent} -> {consequent} (Confidence: {confidence})")
        print("Success")