# CATALOG-ASSIGNMENT
Approach Summary
Input Reading:

Read data from a JSON file that contains key-value pairs representing points in various numerical bases. Each point consists of a base and a value.
Data Decoding:

For each point in the JSON, convert the value from its specified base to decimal using a decoding function. Store these values along with their corresponding indices (used as x-coordinates) in a vector of pairs.
Point Selection:

From the decoded points, select the first k points (as specified in the JSON) for interpolation. This selection is crucial for performing Lagrange interpolation, which requires k data points.
Lagrange Interpolation:

Implement the Lagrange interpolation formula to compute the constant term (the polynomial value at x = 0). This involves calculating the contribution of each point to the polynomial based on its x and y values.
Output the Result:

Finally, print the computed constant term, which represents the value of the polynomial evaluated at x = 0.
Key Concepts
Lagrange Interpolation: A mathematical technique to construct a polynomial that passes through a given set of points.
Base Conversion: The process of converting numbers from various bases to a common base (decimal) for mathematical operations.
Dynamic Storage: Using vectors to handle a flexible number of input points, demonstrating efficient memory management in C++.
