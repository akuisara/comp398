hw17
===

### Mega Group Project 2 Proposal
(Sara, Tyler, Bryan)

For our project we plan to create an API to allow easy interaction with a dataset consisting of the Connections system here at Wheaton College (MA). Our current data set consists of information about all possible connections at the college, and we wish to allow users to make queries about certain connections and related information, such as which courses are involved, which division, area, department, etc. are related. We also have plans to allow for more sophisticated queries, such as which connections can be accomplished/are offered in a given semester, and narrowing down which connections are possible in the selected departments, which connections will align with previously taken courses, and more.

Our API will be RESTful, hosted on heroku and powered by a mongolab-hosted MongoDB database. The queries will take the form of GET and POST requests to structured routes (a.k.a. URI's) at our heroku domain, responding with data in JSON format.