# % % Prolog is a logic programming language that is particularly well-suited for implementing systems based on predicate logic. In predicate logic, propositions are expressed as predicates, which are statements that can be true or false depending on the values of their arguments. Prolog programs consist of a set of predicates and rules, which define relationships between predicates.
# % The high-level overview of how to implement predicate logic in Prolog:
# % 1.	Define Predicates: In Prolog, predicates are defined using facts and rules. Facts are statements about predicates that are assumed to be true. Rules are used to define relationships between predicates based on certain conditions.
# % 2.	Define Rules: Rules in Prolog specify conditions under which predicates are true. These conditions are expressed using logical operators like conjunction (,), disjunction (;), and implication (:-).
# % 3.	Query Predicates: Once you've defined your predicates and rules, you can query them to ask questions or infer new information. Prolog will search for solutions that satisfy the conditions specified in the rules.

# % Code:
# % % Define the rules for the expert system
# % % Example rules for a medical diagnosis system
#  Symptoms:

 symptom(fever).
 symptom(headache).
 symptom(rash).
 symptom(nausea).
 symptom(vomiting).
 symptom(diarrhea).
 symptom(fatigue).
 symptom(abdominal_pain).
 symptom(chest_pain).
 symptom(shortness_of_breath).

#  Diseases:
 disease(measles) :- symptom(fever), symptom(rash).
 disease(meningitis) :- symptom(fever), symptom(headache), symptom(nausea), symptom(vomiting).
 disease(gastroenteritis) :- symptom(nausea), symptom(vomiting), symptom(diarrhea), symptom(abdominal_pain), symptom(fatigue).
 disease(angina) :- symptom(chest_pain), symptom(shortness_of_breath).

# Define the main function to diagnose the disease based on symptoms
 diagnose(Disease) :-
     disease(Disease),
     write('The patient may have '), write(Disease), nl.
 diagnose(_) :-
     write('Unable to diagnose the disease based on the given symptoms.'), nl.


# % how to run
# % 1) ['file_name.pl'].
# % 2) diagnose(measles)
# % 3) diagnose(disease), symptom(fever), symptom(rash).



