// src/BST.js
import React, { Component } from 'react';
import './BST.css'; // Import the CSS file

class BST extends Component {
  // Add any BST logic or methods here

  render() {
    const { data } = this.props; // Access the BST data from props

    return (
      <div className="bst-container">
        {/* Render BST nodes based on the data */}
        {data.map((value, index) => (
          <div key={index} className="bst-node">
            {value}
          </div>
        ))}
      </div>
    );
  }
}

export default BST;
